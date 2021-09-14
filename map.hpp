/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:26 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/14 11:33:42 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include <cstring>
# include "common/others.hpp"
# include "common/random_access_iterator.hpp"
# include "common/reverse_iterator.hpp"
# include "common/lexicographical_compare.hpp"
# include "common/iterator.hpp"
# include "common/iterator_traits.hpp"
# include "common/enable_if.hpp"
# include "common/is_integral.hpp"
# include "common/binary_search_tree.hpp"
# include "common/pair.hpp"

// namespace ft
// {
// 	template <class Key,								  			// map::key_type
// 			  class T,									  			// map::mapped_type
// 			  class Compare = ft::less<Key>,						// map::key_compare
// 			  class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
// 			  >
// 	class map
// 	{
// 		public:
// 			typedef Key											key_type;
// 			typedef T											mapped_type;
// 			typedef ft::pair<key_type, mapped_type> 			value_type;
// 			typedef Compare										key_compare;

// 			class value_compare : ft::binary_function<value_type, value_type, bool>
// 			{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
// 				friend class map<key_type, mapped_type, key_compare, Alloc>;

// 				protected:
// 					Compare comp;
// 					value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
// 				public:
// 					typedef bool result_type;
// 					typedef value_type first_argument_type;
// 					typedef value_type second_argument_type;
// 					bool operator()(const value_type &x, const value_type &y) const
// 					{
// 						return comp(x.first, y.first);
// 					}
// 			};

// 			typedef Alloc										allocator_type;
// 			typedef typename allocator_type::reference			reference;
// 			typedef typename allocator_type::const_reference	const_reference;
// 			typedef typename allocator_type::pointer		 	pointer;
// 			typedef typename allocator_type::const_pointer		const_pointer;
// 			typedef typename ft::binary_search_tree<value_type, key_compare>::iterator iterator;
// 			typedef typename ft::binary_search_tree<value_type, key_compare>::const_iterator const_iterator;
// 			typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
// 			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
// 			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
// 			typedef size_t										size_type;
			
// 			// Constructors:
// 			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
// 				: _alloc(alloc), _comp(comp), _bst()
// 			{

// 			}
			
// 			template <class InputIterator> 
// 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
// 				: _alloc(alloc), _comp(comp), _bst()
// 			{
// 				bool is_valid;
// 				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
// 					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
// 				insert(first, last);
// 			}

// 			map(const map& x) : _alloc(x._alloc), _comp(x._comp), _bst()
// 			{
// 				insert(x.begin(), x.end());
// 			}

// 			~map()
// 			{
// 				clear();
// 			}

// 			// Operators:
// 			map &operator=(const map &x)
// 			{
// 				if (&x == this)
// 					return (*this);
// 				clear();
// 				insert(x.begin(), x.end());
// 				return (*this);
// 			}

// 			// Iterators:
// 			iterator begin()
// 			{
// 				return (iterator(_bst._last_node->left, _bst._last_node));
// 			}
// 			const_iterator begin() const
// 			{
// 				return (const_iterator(_bst._last_node->left, _bst._last_node));
// 			}
// 			iterator end()
// 			{
// 				return (iterator(_bst._last_node, _bst._last_node));
// 			}
// 			const_iterator end() const
// 			{
// 				return (const_iterator(_bst._last_node, _bst._last_node));
// 			}
// 			reverse_iterator rbegin()
// 			{ 
// 				return (reverse_iterator(end()));
// 			}
// 			const_reverse_iterator rbegin() const
// 			{
// 				return (const_reverse_iterator(end()));
// 			}
// 			reverse_iterator rend()
// 			{
// 				return (reverse_iterator(begin()));
// 			}
// 			const_reverse_iterator rend() const
// 			{
// 				return (const_reverse_iterator(begin()));
// 			}
			
// 			// Capacity:
// 			bool empty() const
// 			{
// 				return (_bst._last_node->parent == _bst._last_node);
// 			}
// 			size_type size() const
// 			{
// 				return (_bst._last_node->value.first);
// 			}
// 			size_type max_size() const
// 			{ 
// 				return (_bst.max_size());
// 			}

// 			// Element access:
// 			mapped_type &operator[](const key_type &k)
// 			{
// 				iterator tmp = find(k);

// 				if (tmp == end())
// 					insert(ft::make_pair(k, mapped_type()));
// 				tmp = find(k);
// 				return ((*tmp).second);
// 			}
			
// 			// Modifiers:
// 			pair<iterator, bool> insert(const value_type &val)
// 			{
// 				return (_bst.insertPair(val));
// 			}
// 			iterator insert(iterator position, const value_type &val)
// 			{
// 				(void)position;
// 				return (_bst.insertPair(val).first);
// 			}
// 			template <class InputIterator>
// 			void insert (InputIterator first, InputIterator last,
// 				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
// 			{
// 				bool is_valid;
// 				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
// 					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());

// 				difference_type n = ft::distance(first, last);
// 				while (n--)
// 					insert(*(first++));
// 			}
// 			void erase (iterator position)
// 			{
// 				erase((*position).first);
// 			}
// 			size_type erase(const key_type &k)
// 			{
// 				if (find(k) == end())
// 					return (0);
// 				_bst.removeByKey(ft::make_pair(k, mapped_type()));
// 				return (1);
// 			}
// 			void erase(iterator first, iterator last)
// 			{
// 				while (first != last)
// 					erase((*(first++)).first);
// 			}
// 			void swap(map &x)
// 			{
// 				_bst.swap(x._bst);
// 			}
// 			void clear()
// 			{
// 				erase(begin(), end());
// 			}

// 			// Observers:
// 			key_compare key_comp() const
// 			{
// 				return (key_compare());
// 			}
// 			value_compare value_comp() const
// 			{
// 				return (value_compare(key_compare()));
// 			}
			
// 			// Operations:
// 			iterator find(const key_type &k)
// 			{
// 				return (iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
// 			}
// 			const_iterator find(const key_type &k) const
// 			{
// 				return (const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
// 			}
// 			size_type count(const key_type &k) const
// 			{
// 				const_iterator beg = begin();
// 				const_iterator end = end();

// 				while (beg != end)
// 					if ((*(beg++)).first == k)
// 						return (1);
// 				return (0);
// 			}
// 			const_iterator lower_bound(const key_type &k) const
// 			{
// 				return (const_iterator(lower_bound(k)));
// 			}
// 			iterator upper_bound(const key_type &k)
// 			{
// 				iterator beg = begin();
// 				iterator end = end();

// 				while (beg != end)
// 				{
// 					if (_comp(k, (*beg).first))
// 						break;
// 					beg++;
// 				}
// 				return (beg);
// 			}
// 			const_iterator upper_bound(const key_type &k) const
// 			{
// 				return (const_iterator(upper_bound(k)));
// 			}
// 			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
// 			{ 
// 				return (ft::make_pair(lower_bound(k), upper_bound(k)));
// 			}
// 			ft::pair<iterator, iterator> equal_range (const key_type& k)
// 			{ 
// 				return (ft::make_pair(lower_bound(k), upper_bound(k)));
// 			}

// 			private:
// 				allocator_type							_alloc;
// 				Compare									_comp;
// 				binary_search_tree<value_type, Compare>	_bst;
// 	};
// }


namespace ft
{
	template <bool B, class T = void>
	struct Enable_if {};

	template <class T>
	struct Enable_if<true, T>
	{
		typedef T type;
	};

	template<typename T>
	void ft_swap(T &arg1, T &arg2)
	{
		T temp = arg1;
		arg1 = arg2;
		arg2 = temp;
    }
	///////////////////////////////////Standard specializations//////////////////////////////
	template <typename T>
	struct is_integer
	{
		static const bool value = false;
	};

	template <>
	struct is_integer<int> { static const bool value = true; };
	template <>
	struct is_integer<char> {	static const bool value = true; };
	template <>
	struct is_integer<bool> {	static const bool value = true; };
	template <>
	struct is_integer<signed char> {	static const bool value = true; };
	template <>
	struct is_integer<unsigned char> {	static const bool value = true; };
	template <>
	struct is_integer<wchar_t> {	static const bool value = true; };
	// template <>
	// struct is_integer<char16_t> {	static const bool value = true; };
	// template <>
	// struct is_integer<char32_t> {	static const bool value = true; };
	template <>
	struct is_integer<short> {	static const bool value = true; };
	template <>
	struct is_integer<unsigned int> {	static const bool value = true; };
	template <>
	struct is_integer<long> {	static const bool value = true; };
	template <>
	struct is_integer<long long> {	static const bool value = true; };
	template <>
	struct is_integer<unsigned long long> {	static const bool value = true; };
	// template <>
	// struct is_integer<float> {	static const bool value = true; };
	// template <>
	// struct is_integer<double> {	static const bool value = true; };
	// template <>
	// struct is_integer<long double> {	static const bool value = true; };

}

namespace ft
{


	template <typename T1, typename T2>
	class pair
	{
		public:
		// ******** Data ********
			T1	  first;
			T2	 second;
		// ******** Member function ********
			pair() : first(T1()), second(T2()) { };
			template<class U, class V>
			pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) { };
			pair (const T1& a, const T2& b) : first(a), second(b) { };
			pair (T1& a, T2& b) : first(a), second(b) { };

			~pair() {};

			pair& operator=(const pair & pr)
			{
				if (this != &pr)
				{
					this->first = pr.first;
					this->second = pr.second;
				}
				return (*this);
			}
	
	};
		template <class T1,class T2>
			pair<T1,T2> make_pair (T1 x, T2 y)
			{
				return ( pair<T1,T2>(x,y) );
			}
	template <	class Key,                                        // map::key_type
			class T,                                             // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >   // map::allocator_type
			>

	class map
	{
		public:
			typedef pair<const Key, T>					value_type;
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef T& 									reference;
			typedef Compare								key_compare;
			typedef Alloc								allocator_type;
			typedef const T&							const_reference;
			typedef value_type*							pointer;
			typedef T* const 							const_pointer;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;
			typedef std::forward_iterator_tag			iterator_category;


			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};


			typedef struct								s_node
			{
				int										type_node;
				value_type								*data;
				struct s_node							*parent;
				struct s_node							*left;
				struct s_node							*right;
				bool	is_leaf(struct s_node *node)
				{
					if (node && node->left == NULL && node->right == NULL)
						return (true);
					return (false);
				}
				/*
				to increment there are mains two cases:
				** one -> leaf or node don't have child on the right
						 do to : backtrack to find greater parent
				** interior node
						do to : one step on the right then forward on the left
				*/
				struct s_node *get_next_node()//get sucessor
				{
					key_compare cmp;
					t_node	*node = this;
					if (is_leaf(node) || !node->right)
					{
						while (cmp(this->data->first, node->data->first) == false)
						{
							node = node->parent;
						}
					}
					else
					{
						node = node->right;
						while (node->left)
						{
							node = node->left;
						}
					}
					return (node);
				}

				struct s_node *get_prev_node()//get sucessor predecessor
				{
					key_compare cmp;
					t_node	*node = this;
					if (is_leaf(node) || !node->left)
					{
						node = node->parent;
						while (cmp(this->data->first, node->data->first) == true)
						{
							node = node->parent;
						}
					}
					else
					{
						node = node->left;
						while (node->right)
						{
							node = node->right;
						}
					}
					return (node);
				}
			}											t_node;
		protected:
			t_node										*_root;
			t_node										*_end;
			t_node										*_begin;
			size_type									_size;
			key_compare									_comp;
			std::allocator<struct s_node>				_alloc_node;
			allocator_type								_alloc_pair;

		public:
		///////////////////////iterator/////////////////////////////////

 			class iterator
			{
				private:
					t_node								*_ptr;
				public:
					typedef t_node						*pointeur;
					// typedef ptrdiff_t					difference_type;


					iterator(t_node *ptr = 0): _ptr(ptr){}
					iterator(iterator const &cp){_ptr = cp.get_ptr(	);}
					iterator operator=(iterator const &cp)
					{
						if (this != &cp)
							this->_ptr = cp.get_ptr();
						return *this;
					}

					~iterator(){}
					value_type							&operator*()const {return (*_ptr->data);}
					value_type							*operator->()const {return &(*_ptr->data);}
					iterator							&operator++(){_ptr = _ptr->get_next_node(); return *this;}//++a
					iterator							operator++(int)	{iterator it = *this; _ptr = _ptr->get_next_node(); return (it);}//a++
					iterator							&operator--(){ _ptr = _ptr->get_prev_node(); return (*this);}//--a
					iterator							operator--(int){iterator it = *this; _ptr = _ptr->get_prev_node(); return it;} //a--
					pointeur        					get_ptr()const{return _ptr;}
					bool								operator==(const iterator &it){ return _ptr == it.get_ptr();}
					bool								operator!=(const iterator &it){ return _ptr != it.get_ptr();}
					friend bool 						operator!=(const iterator& a, const   iterator& b) { return a._ptr != b._ptr; };
			};


public:
		///////////////////////iterator/////////////////////////////////

 			class reverse_iterator
			{
				private:
					t_node								*_ptr;
				public:
					typedef t_node						*pointeur;
					// typedef ptrdiff_t					difference_type;


					reverse_iterator(t_node *ptr = 0): _ptr(ptr){}
					reverse_iterator(reverse_iterator const &cp){_ptr = cp.get_ptr(	);}
					reverse_iterator operator=(reverse_iterator const &cp)
					{
						if (this != &cp)
							this->_ptr = cp.get_ptr();
						return *this;
					}

					~reverse_iterator(){}
					value_type							&operator*()const {return (*_ptr->data);}
					value_type							*operator->()const {return &(*_ptr->data);}
					// reverse_iterator							&operator++(){_ptr = _ptr->get_next_node(); return *this;}//++a
					reverse_iterator					&operator++(){ _ptr = _ptr->get_prev_node(); return (*this);}//++a

					// reverse_iterator					operator++(int)	{reverse_iterator it = *this; _ptr = _ptr->get_next_node(); return (it);}//a++
					reverse_iterator					operator++(int)	{reverse_iterator it = *this; _ptr = _ptr->get_prev_node(); return it;}//a++

					reverse_iterator					&operator--(){ _ptr = _ptr->get_next_node(); return *this;}//--a

					reverse_iterator					operator--(int){reverse_iterator it = *this; _ptr = _ptr->get_next_node(); return (it);} //a--
					pointeur        					get_ptr()const{return _ptr;}
					bool								operator==(const reverse_iterator &it){ return _ptr == it.get_ptr();}
					bool								operator!=(const reverse_iterator &it){ return _ptr != it.get_ptr();}
					friend bool 						operator!=(const reverse_iterator& a, const   reverse_iterator& b) { return a._ptr != b._ptr; };
			};



			class const_iterator
			{
				private:
					t_node								*_ptr;
				public:
					typedef t_node						*pointeur;
					// typedef ptrdiff_t					difference_type;


					const_iterator(t_node *ptr = 0): _ptr(ptr){}
					const_iterator(const_iterator const &cp){_ptr = cp.get_ptr(	);}
					const_iterator operator=(const_iterator const &cp)
					{
						if (this != &cp)
							this->_ptr = cp.get_ptr();
						return *this;
					}

					~const_iterator(){}
					value_type							&operator*()const {return (*_ptr->data);}
					value_type							*operator->()const {return &(*_ptr->data);}
					const_iterator						&operator++(){_ptr = _ptr->get_next_node(); return *this;}//++a
					const_iterator						operator++(int)	{const_iterator it = *this; _ptr = _ptr->get_next_node(); return (it);}//a++
					const_iterator						&operator--(){ _ptr = _ptr->get_prev_node(_ptr); return (*this);}//--a
					const_iterator						operator--(int){iterator it = *this; _ptr = _ptr->get_prev_node(); return it;} //a--
					pointeur        					get_ptr()const{return _ptr;}
					bool								operator==(const const_iterator &it){ return _ptr == it.get_ptr();}
					bool								operator!=(const const_iterator &it){ return _ptr != it.get_ptr();}
					friend bool 						operator!=(const const_iterator& a, const   const_iterator& b) { return a._ptr != b._ptr; };
			};

			const_iterator begin() const {return (_begin->parent);}

			const_iterator end() const 	{return (_end);	}


			iterator begin(){return (_begin->parent);}

			iterator end()	{return (_end);	}

			reverse_iterator rend()	{return (_begin);	}

			reverse_iterator rbegin(){return (_end->parent);}

			void	init_node(t_node **node, t_node *parent ,const value_type & val)
			{
				*node = _alloc_node.allocate(1);
				(*node)->data = _alloc_pair.allocate(1);
 				_alloc_pair.construct((*node)->data, val);
				(*node)->parent = parent;
				(*node)->left = 0;
				(*node)->right = 0;
				(*node)->type_node = 0;

			}

///////////////////////constructor////////////////////////////////

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(0), _end(0), _begin(0), _size(0), _comp(comp), _alloc_pair(alloc)
			{
				(void)comp;
				(void)alloc;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(0), _end(0), _begin(0), _size(0),  _comp(comp),  _alloc_pair(alloc)
			{
				while (first != last)
				{
					my_insert (*first, &_root, _root);
					(void)alloc;
					first++;
				}
			}

			map (const map& x):_root(0), _end(0), _begin(0), _size(0), _comp(x._comp), _alloc_pair(x._alloc_pair)
			{
				insert(x.begin(), x.end());
			}

			~map()
			{
				my_clear_tree(_root);
			}

////////////////////////////////capacity//////////////////////
			bool empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			size_type size() const {return (_size);}

			size_type max_size() const
			{
				return (_alloc_node.max_size());
			}



//////////////////////////Modifiers////////////////////////////

			void swap (map& x)
            {
                ft::ft_swap(_size, x._size);
                ft::ft_swap(_root, x._root);
                ft::ft_swap(_end, x._end);
				ft::ft_swap(_begin, x._begin);
                ft::ft_swap(_comp, x._comp);
                ft::ft_swap(_alloc_pair, x._alloc_pair);
                // ft::ft_swap(_alloc, x._alloc);
				
                ft::ft_swap(_alloc_node, x._alloc_node);
            }

			void	my_clear_tree(t_node *node)
			{
				if (node)
				{
					my_clear_tree(node->left);
					my_clear_tree(node->right);
					_alloc_pair.destroy(node->data);
					_alloc_pair.deallocate(node->data, 1);
					_alloc_node.destroy(node);
					_alloc_node.deallocate(node, 1);
				}
				_root = 0;
				_size = 0;
				_end = 0;
				_begin = 0;
			}


/////////////////////////////Element access////////////////////////////

			t_node	*find_key(t_node *node, const key_type & toFind)const
			{
				t_node *ret = 0;
				if (node && node != _begin && node != _end)
				{
					if (node && _comp(node->data->first, toFind) == false && _comp(toFind, node->data->first) == false)
						return (node);
					else
					{
						ret = find_key(node->left, toFind);
						if (!ret)
							ret = find_key(node->right, toFind);
					}
				}
				return (ret);
			}

			mapped_type& operator[] (const key_type& k)
			{
				t_node *node = find_key(_root, k);
				if (node == NULL)
				{
					value_type val(k, mapped_type());
					my_insert (val, &_root, _root);
					node = find_key(_root, k);
				}
				return (node->data->second);
			}

			iterator find (const key_type& k)
			{
				t_node *node = find_key(_root, k);
				if (node)
				{
					// std::cout << "trouveeer" << std::endl;
					return (iterator(node));
				}
				// std::cout << "pas trouveeer" << std::endl;
				return (iterator(_end));
			}

// ///////////////////////////modify//////////////////////////////////////
			void delete_node(t_node *node)
			{
				_size--;
				_alloc_node.destroy(node);
				_alloc_pair.destroy(node->data);
				_alloc_pair.deallocate(node->data, 1);
				_alloc_node.deallocate(node, 1);
			}

			t_node *has_only_one_child(t_node *to_delete)
			{
				t_node* temp = NULL;
				if (to_delete->left == NULL)
				{
					// std::cout << "GAUCH NULL" << std::endl;
					// std::cout << "to_delete->data->first = " << to_delete->data->first << std::endl;
					temp = to_delete->right;
				}
				else if (to_delete->right == NULL)
				{
					temp = to_delete->left;
				}
				if (temp)
					temp->parent = to_delete->parent;
				delete_node(to_delete);
				return (temp);
			}

			void	has_two_children(t_node *root)
			{
				t_node *succesor = root->get_next_node();
				if (succesor->parent != root)
				{
					succesor->parent->left = succesor->right;
					if (succesor->right)
						succesor->right->parent = succesor->parent;
				}
				else
				{
					succesor->parent->right = succesor->right;
					if (succesor->right)
						succesor->right->parent = succesor->parent;
				}
				ft_swap(succesor->data, root->data);
				if (succesor == _end)
					_end = root;
				else if (succesor == _begin)
					_begin = root;
				delete_node(succesor);
			}

			t_node	*delete_one_node_by_key(t_node *root, Key toFind)
			{
				if (!root )
					return (root);
				if (_comp(root->data->first, toFind))
				{
					root->right = delete_one_node_by_key(root->right, toFind);
				}
				else if (!_comp(root->data->first, toFind) && _comp(toFind, root->data->first) )
				{
					root->left = delete_one_node_by_key(root->left, toFind);
				}
				else
				{
					if (root->right == NULL || root->left == NULL )/* If one of the children is empty*/
						root = has_only_one_child(root);
					else
					{
						has_two_children(root);
					}
				}
				return (root);
			}

			

			void erase (iterator position)
			{
				(void)delete_one_node_by_key(_root, position->first);

				(void)position;
			}

			size_type erase (const key_type & k)
			{
				(void)delete_one_node_by_key(_root, k);
				return (1);
			}

			void erase (iterator first, iterator last)
			{
				while (first->first != last->first)
				{
					iterator to_delete = first++;
					(void)delete_one_node_by_key(_root, to_delete->first);
				}
			}

			void	update_node_end(t_node *new_node)
			{
				if (!_end)
				{
					init_node(&_end, new_node, value_type());
					new_node->right = _end;
					_end->parent = new_node;
				}
				else if (new_node->parent->right == new_node && new_node->parent == _end->parent)
				{
					new_node->right = _end;
					_end->parent = new_node;
				}
			}

			void	update_node_begin(t_node *new_node)
			{
				if (!_begin)
				{
					init_node(&_begin, new_node, value_type());
					new_node->left = _begin;
					_begin->parent = new_node;
				}
				else if (new_node->parent->left == new_node && new_node->parent == _begin->parent)
				{
					new_node->left = _begin;
					_begin->parent = new_node;
				}
			}


			void my_insert (const value_type & val, t_node **node, t_node *parent)
			{
				if (_size == 0 && _root)
					my_clear_tree(_root);
				if (!*node || *node == _end || *node == _begin)
				{
					_size++;
					init_node(node, parent, val);
					update_node_end(*node);
					update_node_begin(*node);
				}
				else if (_comp((*node)->data->first, val.first))
				{
					my_insert(val, &(*node)->right, *node);
				}
				else if (_comp((*node)->data->first, val.first) == false)
				{
					if (_comp(val.first, (*node)->data->first) == false)
						return ;
					my_insert(val, &(*node)->left, *node);
				}
			}

			pair<iterator,bool> insert (const value_type& val)
			{
				ft::pair<iterator,bool> ret;
				t_node *test = find_key(_root, val.first);
				if (test == NULL)
				{
					ret.second = true;
				}
				else
				{
					ret.second = false;
				}
				if (ret.second == true)
				{
					my_insert (val, &_root, _root);
				}
				ret.first = iterator(find_key(_root, val.first));
				(void)val;
				return (ret);
			}

			template <class InputIterator>
			// void insert (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
			void insert (typename ft::Enable_if<!ft::is_integer<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				while (first != last)
				{
					value_type val = *first;
					my_insert(*first, &_root, _root);
					first++;
				}

			}

			iterator insert (iterator position, const value_type& val)
			{
				t_node *node = find_key(_root, val.first);
				if (!node)
				{
					my_insert(val, &_root, _root);
					node = find_key(_root, val.first);
				}

				(void)position;
				(void)val;
				return iterator(node);
			}

			void clear()
			{
				my_clear_tree(_root);
			}

//////////////////////////////////////Operations:////////////////////
			size_type count (const key_type& k) const
			{
				if ( find_key(_root, k) == NULL)
					return 0;
				return (1);
			}

			iterator lower_bound (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
				{
					return (it);
				}
				for (it = begin() ; it != end() ; it++)
				{
					if (!_comp(it->first, k))
						return (it);
				}
				return (end());
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = find(k);
				if (it != end())
				{
					return (it);
				}
				for (it = begin() ; it != end() ; it++)
				{
					if (!_comp(it->first, k))
						return (it);
				}
				return (end());
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
				{
					for (it = begin() ; it != end() ; it++ )
					{
						if (_comp(k, it->first))
							return (it);
					}
				}
				return (end());
			}

			const_iterator upper_bound (const key_type& k) const
			{
				const iterator it = find(k);
				if (it != end())
				{
					for (it = begin() ; it != end() ; it++ )
					{
						if (_comp(k, it->first))
							return (it);
					}
				}
				return (end());
			}

			pair<iterator,iterator>             equal_range (const key_type& k)
            {
                pair<iterator,iterator> ret(lower_bound(k), upper_bound(k));
                return ret;
            }

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				pair<const_iterator,const_iterator> ret(const_iterator(lower_bound(k)), const_iterator(upper_bound(k)));
				return (ret);
			}

			map& operator=(const map& x)
            {
				my_clear_tree(_root);
				if (x._size != 0)
               		insert(x.begin(), x.end());
                return (*this);
            }
			key_compare key_comp() const{return _comp;}
			value_compare value_comp() const{return value_compare(_comp);}


	};
}
#endif
